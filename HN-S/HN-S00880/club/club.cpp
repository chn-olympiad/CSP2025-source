#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int t,n;
int a[N],b[N],c[N]; 

bool vis[N];

int f(int n,int m,int k){
	int mx = max(n,m);
	return max(mx,k);
}

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		for(int j = 1;j <= n;j++){
			cin >> a[i] >> b[i] >> c[i];
		}
		int x=0,y=0,z=0;
		int x_old=0,ix=0,y_old=0,iy=0,z_old=0,iz=0;
		for(int j = 1;j <= n;j++){
			int d = f(a[j],b[j],c[j]);
			if(d == a[j]){
				if(a[j] > x_old){
					x -= x_old;
					x_old = a[j];
					vis[ix] = 0;
					ix = j;
					
				}
				x+=a[j];
				vis[j] = 1;
				
			}
			if(d == b[j]){
				if(b[j] > y_old){
					y -= y_old;
					y_old = b[j];
					vis[iy] = 0;
					iy = j;
					
				}
				y+=b[j];
				vis[j] = 1;
			}
			if(d == c[j]){
				if(c[j] > z_old){
					z -= z_old;
					z_old = c[j];
					vis[iz] = 0;
					iz = j;
					
				}
				z+=c[j];
				vis[j] = 1;
			}
		}
		cout << x << y << z;
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
