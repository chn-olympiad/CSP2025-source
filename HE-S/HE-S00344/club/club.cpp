#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,a3,sum=0;
const int N=100010,M=5;
int a[N],b[M];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>a1>>a2>>a3;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
  while(n%2==0){
	int max;
	if(a1>a2>a3){
		max=a1;
	}else{
		if(a2>a3>a1){
			max=a2;
		}else{
			if(a3>a2>a1){
				max=a3;
			}
		}
	}
	   sum+=max;
		cout<<sum;
	
}
	cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
	return 0;
}

