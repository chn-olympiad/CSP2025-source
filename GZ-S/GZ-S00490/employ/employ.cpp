//GZ-S00490 观山湖外国语实验中学 雷梓珩
#include<bits/stdc++.h>
using namespace std;
int k(int qe){
	int dd=1;
	for(i=qe;i>=1;i--){
		dd=dd*i;
	}
	return dd;
}
int main(){
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdin");
	int n,m,p[10000];
    int nd[1000100];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nd[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int w=1;
	int a=1;
	int v[100100];
	for(int i=1;i<=n;i++){
		for(int j=w;j<=n;j++){
			if(nd[i]==0){
				w=i;
				v[a]=w;
				a+=1;
				break;
			}
			w+=1;
		}                                                            
	}
	int q=v.size();
	int u[100000];
	for(int d=1;d<=q;d++){
		u[d]=k(v[d]);
	}
	cout<<k(n)*m;
	return 0;
	fclose("employ.in","stdout");
	fclose("empoly.out","stdout");
	
}
	
                      
                      
