#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
long long i,sum,n;
bool cmp(int x,int y){
		return x>y;
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
				a[i]=(int)(s[i]-48);
				sum++;
		}
		else{
				a[i]=10;
		}
	}
	sort(a,a+n+1,cmp);
	for(i=0;i<n;i++){
		if(a[i]!=10){
			cout<<a[i];
		}
		
	}
	return 0;
}
