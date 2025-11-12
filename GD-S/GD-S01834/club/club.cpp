#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,sum,q[4][101010],su[4],c[101010]; 
struct ly{
	int ma,man,cm,cmn;
}a[101010];
struct hq{
	int num,sum;
};
bool cmb(hq a,hq b){
	return a.sum>b.sum;
}
bool cmp(ly a,ly b){
	return a.ma>b.ma;
}
bool f[101010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(f,0,sizeof(f));
		memset(q,0,sizeof(q));
		memset(su,0,sizeof(su));
		sum=0;
		for(int i=1;i<=n;i++){
			hq b[5]={};
			for(int j=1;j<=3;j++){
				cin>>b[j].sum;
				b[j].num=j;
			}
			sort(b+1,b+4,cmb);
			a[i]={b[1].sum,b[1].num,b[2].sum,b[2].num};
		}
		for(int i=1;i<=n;i++){
			q[a[i].man][++su[a[i].man]]=i;
			sum+=a[i].ma;
		}
		int flag=0;
		for(int i=1;i<=3;i++){
			if(su[i]>n/2)flag=i;
		}
		if(!flag)cout<<sum<<endl;
		else{
			int k=su[flag]-n/2;
			for(int i=1;i<=su[flag];i++){
				c[i]=a[q[flag][i]].ma-a[q[flag][i]].cm;
			}
			sort(c+1,c+1+su[flag]);
			for(int i=1;i<=k;i++)sum=sum-c[i];
			cout<<sum<<endl;
		}
	}
	return 0;
}//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
//1 10 20 145 189 24 153 163 19 62 16 20 99 197 83 105 54 35 146 179 61 134 166 87 5 43 9 31 99 164 53 109
/*1 10
 20 145 189
 24 153 163
 19 62 161
 20 99 197
 83 105 54
 35 146 179
 61 134 166
 87 5 43
 9 31 99
 164 53 109对民主的认识：
1.人民当家作主是社会主义民主政治的本质特征，全过程人民民主是社会主义民主政治的本质属性
2.全过程人民民主是最真实，最广泛，最管用的民主
3.党的领导是实现全过程人民民主的根本保证
4.我国既实行协商民主，又实行选举民主
5.有事好商量，众人的事众人商量是民主的真谛，协商民主是我国独特优势和特有形式
6.全过程人民民主的意义：有利于体现社会主义国家性质，彰显人民主体地位，体现人民意志，维护人民合法权益，进一步激发人民创造潜力
7.人民代表大会制度，中国共产党领导的多党合作和政治协商制度，基层群众自治制度，民族区域自治制度有利于实现人民民主*/
