#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005],h[500005],fs,fq[500005],fh[500005],ans,maxt=-1,ys;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],q[i]=q[i-1]^a[i],maxt=max(maxt,a[i]),ys+=(a[i]==1);
	if(maxt==1&&m==1)
		cout<<ys,exit(0);
	for(int i=n;i>=1;i--)
		h[i]=h[i+1]^a[i];
	/*for(int i=1;i<=n;i++)
		cout<<q[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<h[i]<<" ";
	cout<<endl;*/
	//cout<<(q[n]^q[1]^h[3]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
		{
			if(fq[j-1]+fh[j+i]==fs)
			{
				//if(j==1&&j+i-1==2)
				//	cout<<(q[n]^q[j-1]^h[j+i])<<endl;
				//cout<<" "<<(q[n]^q[j-1]^h[j+i])<<"="<<m<<endl;
				if((q[n]^q[j-1]^h[j+i])==m)
				{
					long long js=0;
					ans++;
					//cout<<" "<<q[n]<<" "<<q[j-1]<<" "<<h[j+i]<<endl;
					//cout<<j<<" "<<j+i-1<<endl;
					fs+=i;
					for(int k=j;k<=n;k++)
						js+=(k<=j+i-1),fq[k]+=js;
					js=0;
					for(int k=j+i-1;k>=1;k--)
						js+=(k>=j),fh[k]+=js;
				}
			}	
		}
	cout<<ans;
	return 0;
}
