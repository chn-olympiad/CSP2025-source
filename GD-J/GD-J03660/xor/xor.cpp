#include<bits/stdc++.h>
using namespace std;
int n,k;
int a1[6000000];
int a[6000000];

int ehh(int e1,int e2){
	int b[100000][10];
	int q1=1,q2=1,nu=0; 
	while(e1>0){
		b[q1][1]=e1%2;
		e1=e1/2;
		q1++;
	}
	while(e2>0){
		b[q2][2]=e2%2;
		e2=e2/2;
		q2++;
	}
	if(q1<q2){
		q1=q2;
	}
	for(int i=1;i<=q1;i++){
		if(b[i][1]==b[i][2]){
			b[i][3]=0;
		}else{
			b[i][3]=1; 
	}
	}
	for(int i=1;i<=q1;i++){
		nu=(b[i][3]*pow(2,i-1))+nu;
	}
	
	return nu;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	int num,o=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i+=k){
		
		for(int j=i;i<=j+k;j++){
			if(j==i){
				num=a[j];
			} else{
				num=ehh(num,a[j])+num;
			}
		}
		a1[o]=num;
		o++;
		
	}
	sort(a1+1,a1+o+1);
	cout<<a1[o];
	return 0;
}
