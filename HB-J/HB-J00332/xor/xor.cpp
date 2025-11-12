#include<bits/stdc++.h>
using namespace std;
long long n,k,num1,num0,flag,asw;
int ls;
vector<int>a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>ls;
    	if(ls==1) num1++;
    	if(ls==0) num0++;
    	if(ls==1||ls==0) flag++;
    	if(ls==k) asw++;
    	a.push_back(ls);
    }
    if(k==0&&num1==a.size()){
    	cout<<0;
    	return 0;
    }
    if(flag==a.size()&&k==1){
    	cout<<num1;
    	return 0;
    }
    if(flag==a.size()&&k==0){
    	cout<<num0;
    	return 0;
    }
    cout<<asw;
	return 0;
}
