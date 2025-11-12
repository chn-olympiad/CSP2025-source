#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+100; 
string s;
ll a[N],sum;
bool cmp(int q,int b){
	return q>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++,sum++){
		if(s[i]<='9'&&s[i]>='0'){
			a[sum]=s[i]-'0';
			
		
		}
		else {
			continue;
		}
	} 
	sort(a,a+sum,cmp);
	for(int i=0;i<=sum-1;i++){
	cout<<a[i];
	}
	
} 