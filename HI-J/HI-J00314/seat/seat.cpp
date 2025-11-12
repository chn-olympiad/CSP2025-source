#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
vector<int> v; 
int main() {
	int n,m;
	cin>>n>>m;
	int num; 
	for(int i=1;i<n*m;i++){
		cin>>num;
		v.push_back(num);
	}
	int s=v[1];
	int x=0;
	sort(v.begin(),v.end(),cmp);
	int len=v.size();
	for(int i=1;i<=len;i++){
		if(v[i]==s){
			x=i;
		}
	}
	if(x<=n){
		cout<<"1" <<" "<<x;
	} 
	else if(x%n==0){
		if((x/n)%2==0){
			cout<<x/n<<" "<<"1";
		}else{
			cout<<x/n<<" "<<n;
		}
	}
	else{
		if((x/n)%2==0){
			cout<<x/n+1<<" "<<x%n;
		}else{
			cout<<x/n+1<<" "<<n-x%n;
		}
	}
	return 0;
}
