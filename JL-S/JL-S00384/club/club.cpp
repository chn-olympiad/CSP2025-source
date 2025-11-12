#include<bits/stdc++.h>
using namespace std;
long long a[10001];
long long b[10001];
long long c[10001];
long long e;
long long f;
long long g;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n,t;
cin>>t;
while(t>0){
	int x=0,y=0,z=0;
	int s=0;
	cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i]>>b[i]>>c[i];
}
for(int i=1;i<=n;i++){
	 e=max(a[i],b[i]);
	 e=max(e,c[i]);
	 f=max(a[i-1],b[i-1]);
	 f=max(f,c[i-1]);
	 g=max(a[i+1],b[i+1]);
	 g=max(g,c[i+1]);
	if(e==a[i]&&x<=n/2){
		s=s+e;
		x++;
		if(x>n/2){
			int w=max(b[i-1]+e,c[i-1]+e);
			if(w==b[i-1]+e&&y<=n/2){
				s=s-f+b[i-1];
				y++;
				if(y>n/2){
					s=s-f+c[i-1];
					z++;
				}
		}
			if(w==c[i-1]+e&&z<=n/2&&c[i]!=b[i]){
				s=s-f+c[i-1];
				z++;
				if(z>n/2){
					s=s-f+b[i-1];
					y++;
				}
			}
			if(f+e<g+e){
				s=s-f+g;
			}
		}
	}
	if(e==b[i]&&y<=n/2&&e!=a[i]&&e!=c[i]){
		s=s+e;
		y++;
		if(y>n/2){
			int w=max(a[i-1]+e,c[i-1]+e);
			if(w==a[i-1]+e&&x<=n/2){
				s=s-f+a[i-1];
				x++;
				if(x>n/2){
					s=s-f+c[i-1];
					z++;
				}
		}
			if(w==c[i-1]+e&&z<=n/2&&c[i]!=a[i]){
				s=s-f+c[i-1];
				z++;
				if(z>n/2){
					s=s-f+a[i-1];
					x++;
				}
			}		
			if(f+e<g+e){
				s=s-f+g;
			}
		}

	}
	if(e==c[i]&&z<=n/2&&e!=a[i]){
		s=s+e;
		z++;
			if(z>n/2){
			int w=max(a[i-1]+e,b[i-1]+e);
			if(w==b[i-1]+e&&y<=n/2){
				s=s-f+b[i-1];
				y++;
				if(y>n/2){
					s=s-f+a[i-1];
					x++;
				}
		}
			if(w==a[i-1]+e&&z<=n/2&&a[i]!=b[i]){
				s=s-f+a[i-1];
				x++;
				if(x>n/2){
					s=s-f+b[i-1];
					y++;
				}
			}
			if(f+e<g+e){
				s=s-f+g;
			}
		}
	}
}
	cout<<s<<endl;
	t--;
}
	return 0;
}
