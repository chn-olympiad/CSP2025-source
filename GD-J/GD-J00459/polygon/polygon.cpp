#include<bits/stdc++.h>
using namespace std;
int n;
int an=0;
int a[50007];
int h;
int ma=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==1||n==2||n==0) {
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					h=a[i]+a[j]+a[k];
					if(ma<a[i]) ma=a[i];
					if(ma<a[j]) ma=a[j];
					if(ma<a[k]) ma=a[k];
					if(h>2*ma) an++;
				}
			}
		}
	}
	else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					h=a[i]+a[j]+a[k];
					if(ma<a[i]) ma=a[i];
					if(ma<a[j]) ma=a[j];
					if(ma<a[k]) ma=a[k];
					if(h>2*ma) an++;
				}
			}
		}
		ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						h=a[i]+a[j]+a[k]+a[b];
						if(ma<a[i]) ma=a[i];
						if(ma<a[j]) ma=a[j];
						if(ma<a[k]) ma=a[k];
						if(ma<a[b]) ma=a[b];
						if(h>2*ma) an++;
					}
				}
			}
		}
	}
	
	else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					h=a[i]+a[j]+a[k];
					if(ma<a[i]) ma=a[i];
					if(ma<a[j]) ma=a[j];
					if(ma<a[k]) ma=a[k];
					if(h>2*ma) an++;
				}
			}
		}
		ma=0;
		h=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						h=a[i]+a[j]+a[k]+a[b];
						if(ma<a[i]) ma=a[i];
						if(ma<a[j]) ma=a[j];
						if(ma<a[k]) ma=a[k];
						if(ma<a[b]) ma=a[b];
						if(h>2*ma) an++;
					}
				}
			}
		}
		ma=0;
		h=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							h=a[i]+a[j]+a[k]+a[b]+a[c];
							if(ma<a[i]) ma=a[i];
							if(ma<a[j]) ma=a[j];
							if(ma<a[k]) ma=a[k];
							if(ma<a[b]) ma=a[b];
							if(ma<a[c]) ma=a[c];
							if(h>2*ma) an++;
						}
					}
				}
			}
		}
	}
	cout<<an;
	return 0;
} 
