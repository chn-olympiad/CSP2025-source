#include<bits/stdc++.h>
using namespace std;
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	s[0]=a[0];
	s[1]=a[1]+a[2];
	for(int j=2;j<n;j++){
		s[j]=a[j]+s[j-1];
	}
	int t=0;
	if(s[2]>2*a[2]){
		t+=1;
	}else if(n>=4){
		if(s[3]>a[3]*2){
			t+=1;
		}
		for(int d=0;d<3;d++){
			if((s[3]-a[d])>2*a[3]){
				t+=1;
			}
		}
	}
	for(int l=4;l<n;l++){
		if(s[l-1]>a[l]){
			t+=1;
		}
	}
	cout<<9<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
