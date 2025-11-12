#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=1000002;

string s;
int a[maxn],p;

bool cmp(int x,int y){
	return x>y;
}

int main() {
	
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	
	cin>>s;
	int l=int(s.size());
	for(int i=0;i<l;i++){
		
		if(s[i]>='0' and s[i]<='9'){
			
			a[++p]=s[i]-'0';
					
		}
		
	}
	
	sort(a+1,a+p+1,cmp);
	
	for(int i=1;i<=p;i++){
		
		cout<<a[i];
		
	}
	
	return 0;
	
}
