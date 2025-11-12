#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[4][2000005],cz[10005];
int t,wcd=0,ans=0,dl[10005];
int seek(int e){
	int lll=cz[e];
	int jg=0,fl=0;
	int opop=1000000001;
	while(1){
		if(lll==0){
			return jg;
		}else{
			if(a[2][lll]<opop){
				for(int i=1;i<=wcd;i++){
					if(a[1][lll]==dl[i]){
						lll=a[3][lll];
						fl=1;
						break;
					}
				}
				if(fl==1){
					continue;
				}
				opop=a[2][lll];
				jg=lll;
			}
		}
		lll=a[3][lll];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t;
		a[0][i*2-1]=t;
		cin>>t;
		a[1][i*2-1]=t;
		cin>>t;
		a[2][i*2-1]=t;
		if(cz[a[0][i*2-1]]==0){
			cz[a[0][i*2-1]]=i*2-1;
		}else{
			a[3][i*2-1]=cz[a[0][i*2-1]];
			cz[a[0][i*2-1]]=i*2-1;
		}
		a[0][i*2]=a[1][i*2-1];
		a[1][i*2]=a[0][i*2-1];
		a[2][i*2]=a[2][i*2-1];
		if(cz[a[0][i*2]]==0){
			cz[a[0][i*2]]=i*2;
		}else{
			a[3][i*2]=cz[a[0][i*2]];
			cz[a[0][i*2]]=i*2;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>t;
		}
	}
	a[2][0]=1000000001;
	wcd=1;
	dl[wcd]=1;
	int dq=0;
	for(int i=1;i<n;i++){
		dq=0;
		for(int j=1;j<=wcd;j++){
			if(seek(dl[j])>0&&a[2][seek(dl[j])]<a[2][dq]){
				dq=seek(dl[j]);
			}
		}
		wcd++;
		ans+=a[2][dq];
		dl[wcd]=a[1][dq];
		
	/*	for(int j=1;j<=wcd;j++){
			cout<<dl[j]<<" ";
		}
		cout<<endl;*/
		
	}
	cout<<ans;
	return 0;
}

