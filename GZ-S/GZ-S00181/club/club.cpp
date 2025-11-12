//GZ-S00181 毕节梁才学校 张静峰
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
	本题5个测试样例一遍全对，我ztmdnb!!!!!!! 
	思路：
		先用贪心，每一个人都让其去好感度最高的社团(完成）
		接着将每个社团可以让给其他社团而总值减少的数量排序（完成）
		最后换人
*/
vector<int> a,b,c;//三个社团
LL cnt=0;//记录好感总和
int n,t;

int x[500010],y[500010],z[500010];//记录每个人对每个社团的好感度

void clean() { //初始化
	a.clear();
	b.clear();
	c.clear();
	cnt=0;
}

//排序
int get_cha(int p) { //用最大的和其他每个的差的最小值
	int ma=max(x[p],y[p]);
	ma=max(ma,z[p]);
	int mi=0x3f3f3f3f;
	int t=0;
	if(ma-x[p]==0) {
		t++; 
	}else {
		mi=ma-x[p];
	}
	if(ma-y[p]==0) {
		t++;
		if(t>1){
			mi=ma-y[p];
		} 
	}else {
		mi=min(mi,ma-y[p]);
	}
	if(ma-z[p]==0) {
		t++;
		if(t>1){
			mi=min(mi,ma-z[p]);
		} 
	}else {
		mi=min(mi,ma-z[p]);
	}
	return mi;
}

bool cmp(int a,int b) {
	return get_cha(a)<get_cha(b);
}

//换人
void work(vector<int> s) {
	sort(s.begin(),s.end(),cmp);
	int t=0;//换谁
	int num=s.size();
	while(num>n/2) {
		cnt-=get_cha(s[t]);
		//cout<<"_____"<<cnt<<endl;//
		t++;
		num--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		clean();
		scanf("%d",&n);

		bool f1=true,f2=true,f3=true;

		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			if(x[i]>=y[i]&&x[i]>=z[i]) {
				a.push_back(i);
				cnt+=x[i];
				//cout<<"===="<<cnt<<" 1"<<endl;
			} else if(y[i]>=x[i]&&y[i]>=z[i]) {
				b.push_back(i);
				cnt+=y[i];
				//cout<<"===="<<cnt<<" 2"<<endl;
			} else {
				c.push_back(i);
				cnt+=z[i];
				//cout<<"===="<<cnt<<" 3"<<endl;
			}
		}
		
		f1=(a.size()<=n/2);
		f2=(b.size()<=n/2);
		f3=(c.size()<=n/2);
		//cout<<"====="<<f1<<f2<<f3<<endl;
		if(!f1) {
			work(a);
		} else if(!f2) {
			work(b);
			//cout<<"+_+_+_+_"<<endl;
		} else if(!f3) {
			work(c);
		}

		printf("%lld\n",cnt);
	}


	return 0;
}

