#include<bits/stdc++.h>
using namespace std;
long long abg[10010],a[10010][10010],n[10010],b[10010],amax[10010]
int	main{
	fropen(club.in,"r",stdin);
	fropen(club.out,"w",stdout);
	long long t,mx;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		abg[i]=0;
			for(int j=1;j<=t;j++){
					for(int z=1;z<=3;z++){
						cin>>a[j][i];
					}
			}
	}
	nmax=n[i]/2;
	for(int j=1;j<=n[i];j++){
		amax[j]=a[j][2];
	}
	if(amax[j]<a[j][3]){
		amax[j]=a[j][3];
	}
	for(int z=1;z<=3;z++){
		for(int j=1;j<=n[i];j++){
		if (nmax==0)
		break;
		else{
			int kk=0,mz,mxz;
			for(int xz=1;xz<=n[i];xz++){
				if(kk<a[z][xz]){
					kk=a[z][xz];
					mz=z;
					xmz=xz;
				}
			}
			abg[i]=abg[i]+kk;
			for(int xz=1;xz<=3;i++){
				a[xz][j]=0;
				nmax--;
			}
			for(int j=1;j<=n[i];j++){
				int amm=0;
	
			}
		}
		abg[i]+=amm;
		gg--;
	
		}
	}
	for(int i=1;i<=t;i++){
		cout<<abg[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

