#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int i;
int a1[20005],a2[20005],a3[20005];
int b1[20005],b2[20005],b3[20005];
void shuru(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
	}	
}

void fu(){
	for(i=0;i<n;i++){
		b1[i]=a1[1];b2[i]=a2[i];b3[i]=a3[i];
	}
}

void suan(){
	fu();
	sort(b1,b1+n);
	sort(b2,b2+n);
	sort(b3,b3+n);
	for(i=0;i<3;i++){
		if(b1[n-1]>b2[n-1] && b1[n-1]>b3[n-1]){
			
		}
		if(b2[n-1]>b1[n-1] && b1[n-1]>b3[n-1]){
			
		}
		if(b3[n-1]>b2[n-1] && b1[n-1]>b1[n-1]){
			
		}
	}
}

int main(){
	shuru();
	freopen("club.in","r",stdin);
	suan();
	freopen("club.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
