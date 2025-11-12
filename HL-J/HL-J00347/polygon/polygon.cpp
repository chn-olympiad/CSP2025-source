#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int A(int n,int m){
	int ans=1;
	for(int i=0;i<n;i++){
		ans*=(m-i);
	}
	return ans;
}
int C(int n,int m){
	return A(n,m)/A(n,n)%998244353;
}
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int s;
    vector<int>num;
    cin>>s;
    for(int i=0;i<s;i++){
        int f;
        cin>>f;
        num.push_back(f);
    }
    sort(num.begin(),num.end(),cmp);
    cout<<C(s,3);
    return 0;
}
