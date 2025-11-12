# include<bits/stdc++.h>
using namespace std;
int n,q,l[200001],L,R,len[200005];
string s1,s2,t1,t2;
unsigned long long has1[200005],has2[200005],G=523421421221,Pow[10000005],qzh1[10000005],qzh2[10000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	Pow[0]=1;
	for(int j = 1;j<=10000000;j++)Pow[j]=Pow[j-1]*G;
	for(int i = 1;i<=n;i++){
		cin>>s1>>s2,l[i]=-1;
		len[i]=s1.size();
		for(int j = 0;j<(int)s1.size();j++){
			if(s1[j]!=s2[j]&&l[i]==-1)l[i]=j;
			has1[i]+=Pow[j+5000000]*s1[j];
			has2[i]+=Pow[j+5000000]*s2[j];
		}
	}
	while(q--){
		cin>>t1>>t2,L=R=-1;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;};
		for(int j = 0;j<(int)t1.size();j++){
			if(t1[j]!=t2[j]){if(L==-1)L=j;R=j;}
			qzh1[j]=(j==0?0:qzh1[j-1])+Pow[j]*t1[j];
			qzh2[j]=(j==0?0:qzh2[j-1])+Pow[j]*t2[j];
		}
		int ans=0;
		for(int i = 1;i<=n;i++){
			int ls=L-l[i],rs=L+(len[i]-l[i])-1;
//			cout<<i<<" "<<ls<<" "<<rs<<","<<L<<" "<<R<<"\n";
			if(ls>=0&&rs<(int)t1.size()&&rs>=R){
				unsigned long long z1=qzh1[rs]-(ls==0?0:qzh1[ls-1]);
				z1*=Pow[5000000-ls];
				unsigned long long z2=qzh2[rs]-(ls==0?0:qzh2[ls-1]);
				z2*=Pow[5000000-ls];
//				cout<<z1<<" "<<z2<<","<<has1[i]<<" "<<has2[i]<<"\n";
				if(z1==has1[i]&&z2==has2[i])ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
