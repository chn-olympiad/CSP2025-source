#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[505];
int c[505];
int walked[505];
long long sum=0;
string s;
bool all_one=true;

void dfs(int po,int val){//被拒绝的人数：po-1-val(当前天数-1-已被录取的人数)
	//cout<<po<<" "<<val<<endl; 
	if(po==n+1){
		//cout<<"ADDED!!!"<<endl;
		if(val>=m) sum++;
		sum%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!walked[i]){
			walked[i]=1;
			dfs(po+1,val+(po-1-val<c[i]?d[po]:0));
			walked[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=s.length();i++){
		d[i]=s[i-1]-'0';
		if(d[i]==0) all_one=false;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}

if(all_one){//特殊性质A的写法 
	//此时题目简化为求出一段数字的排列方式且某个数字前面的0数量不能大于它的值。
	sort(c+1,c+n+1); 
	//...
	dfs(1,0);//算了还是如此罢。 我们从来都与他人的苟且擦肩而过，从前如此，将来也如一。 =v=
	printf("%lld",sum);
}else{//无特殊性质A，进行DFS
	dfs(1,0);
	printf("%lld",sum);
}
	return 0;
}

