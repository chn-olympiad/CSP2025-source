#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int p=n/2,man=0;
	int a[n+2],b[n+2],c[n+2];
	int ap=0,bp=0,cp=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];	
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	sort(c,c+n,cmp);
	int m=n/3;
	for(int i=0;i<m;i++){
		man+=a[i]+b[i]+c[i];
		ap++;bp++;cp++;
	}
	int qq=n-m*3;
			if(a[m]>b[m]&&a[m]>c[m]){
				if(ap<p){man+=a[m];
			}
		}
		
			else if(b[m]>a[m]&&b[m]>c[m]){
				if(bp<p){man+=b[m];
			}
		}
		else if(c[m]>a[m]&&c[m]>b[m]){
			if(cp<p){
				man+=c[m];
			}
		}
		else {
			man+=a[m];
		}
	if(qq==2){
		m++;
		if(a[m]>b[m]&&a[m]>c[m]){
				if(ap<p){man+=a[m];
			}
		}
		
			else if(b[m]>a[m]&&b[m]>c[m]){
				if(bp<p){man+=b[m];
			}
		}
		else if(c[m]>a[m]&&c[m]>b[m]){
			if(cp<p){
				man+=c[m];
			}
		}
		else {
			man+=a[m];
		}
	}		
	cout<<man<<endl;
}
	return 0;
} 
