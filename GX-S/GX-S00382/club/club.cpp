#include<bits/stdc++.h>
using namespace std;
int a[100005][5];

int comp(float a,float b,float c)
{
	if(a>=b&&a>=c) return 1;
	if(b>=a&&b>=c) return 2;
	if(c>=b&&c>=a) return 3;
}
	

void solve(){
	int n,num[5]={0,0,0,0,0};
	float suma=0,sumb=0,sumc=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		suma+=a[i][1];
		sumb+=a[i][2];
		sumc+=a[i][3];
	}
	suma/=n;sumb/=n;sumc/=n;
	int sum=0,pos;
	for(int i=1;i<=n;++i){
		pos=comp(a[i][1]-suma,a[i][2]-sumb,a[i][3]-sumc);
//		float j1=a[i][1]-suma,j2=a[i][2]-sumb,j3=a[i][3]-sumc;
//		pos=comp(,,);
		
		/*if(a[i][1]>a[i][3]&&a[i][1]-suma<a[i][3]-sumc){
			if(num[1]<=n/2){
				pos=1;
			}
		}
		else if(a[i][1]>a[i][2]&&a[i][1]-suma<a[i][2]-sumb){
			if(num[1]<=n/2){
				pos=1;
			}
		}
		else if(a[i][2]>a[i][3]&&a[i][2]-sumb<a[i][3]-sumc){
			if(num[2]<=n/2){
				pos=2;
			}
		}
		else if(a[i][2]>a[i][1]&&a[i][2]-sumb<a[i][1]-suma){
			if(num[2]<=n/2){
				pos=2;
			}
		}
		else if(a[i][3]>a[i][1]&&a[i][3]-sumc<a[i][1]-suma){
			if(num[3]<=n/2){
				pos=3;
			}
		}
		else if(a[i][3]>a[i][2]&&a[i][3]-sumc<a[i][2]-sumb){
			if(num[3]<=n/2){
				pos=3;
			}
		}*/
		
		sum+=a[i][pos];
		num[pos]++;
		
	}
	cout<<sum<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
