#include<bits/stdc++.h> 
using namespace std;
string s;
int sum,sz[1000005];
bool cmp(int x,int y){
	if(x!=y)return x>y;
	return 0; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			sum++;
			sz[sum]=s[i];
		}
		if(s[i]=='1'){
			sum++;
			sz[sum]=s[i];
		}
		if(s[i]=='2'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='3'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='4'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='5'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='6'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='7'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='8'){
			sum++;
			sz[sum]=s[i];	
		}
		if(s[i]=='9'){
			sum++;
			sz[sum]=s[i];	
		}
	}
	sort(sz+1,sz+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		cout<<sz[sum];
	}
	return 0;
}
