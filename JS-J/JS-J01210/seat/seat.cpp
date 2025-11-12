#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> a;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int ye;
		cin>>ye;
		a.push_back(ye);
	}
	int num=a[0];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int ans;
	for(int i=0;i<n*m;i++){
		if(a[i]==num){
			ans=i+1;
			break;
		}
	}
	int anss=int(ans*1.0/n+0.9),cnt;
	cout<<anss<<" ";
	if(ans%n!=0) cnt=ans%n;
	else cnt=n;
	//cout<<cnt<<endl;
	if(anss%2==0)
		cout<<n-cnt+1<<endl;
	else{
		cout<<cnt<<endl;
	}
	return 0;
}
