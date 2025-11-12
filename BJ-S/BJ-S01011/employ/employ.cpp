#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[515],a2[515];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a2[i]);
	}
	if(m==n){
		bool a1=true;
		for(int i=0;i<n;i++){
			if(a[i]!=1){
				a1=false;
				break;
			}
		}
		if(a1) printf("1");
	}
	
	return 0;
}
