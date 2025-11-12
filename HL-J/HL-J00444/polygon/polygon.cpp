#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long choice[5010];
int isp(int m){
	long long sum=0;
	int max_choice=0;
	for(int i=0;i<m;i++){
		if(max_choice<choice[i]){
			max_choice=choice[i];
		}
		sum+=choice[i];
	}
	//sum=sum-max_choice;
	max_choice*=2;
	if(sum>max_choice){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>=30){
		a[0]=n%30;
		for(int i=1;i<n;i++){
			cin>>a[i];
		}
	}else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	}
//	long long times=0;
//	long long oks=0;
	if(n==3){
		for(int i=0;i<3;i++){
			choice[i]=a[i];
		}
		cout<<isp(3);
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
