#include<bits/stdc++.h>
using namespace std;


int a[500005],n,k;

string totwo(int num){
	string ans;
	queue<bool> st;
	while(num){
		st.push(num%2);
		num/=2;
	}
	while(!st.empty()){
		ans+=st.front()+'0';
		st.pop();
	}
	return ans;
}
int xorab(int a,int b){
	int ans=0;
	string stranstwo="";
	string s1=totwo(a),s2=totwo(b);
	
	int n=min(s1.size(),s2.size());
	for(int i=0;i<n;i++){
		stranstwo+=((s1[i]=='0' && s2[i]=='1') || (s1[i]=='1' && s2[i]=='0')? '1':'0');
	}
	if(s1.size()>n){
		for(int i=n;i<s1.size();i++){
			stranstwo+=s1[i];
		}
	}else if(s2.size()>n){
		for(int i=n;i<s2.size();i++){
			stranstwo+=s2[i];
		}
	}
	long long q=1;
	for(int i=0;i<stranstwo.size();i++){
		ans+=(stranstwo[i]-'0')*q;
		q*=2;
	}
	return ans;
}

bool xorlr(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=xorab(sum,a[i]);
	}
	return sum==k;
}
bool check(int mid,int step){//能否求出step后有mid个满足条件区间 
	//cout<<step<<endl;
	bool flag=0;
	if(mid==0){
		//cout<<step<<endl;
		return true;
		
	}
	if(step>n){
		return false;
	}
	int minstep=n+1;
	for(int l=step;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(xorlr(l,r)){
				minstep=min(r+1,minstep);
				flag=1;
				//break;
			}
		}
	}
	if(flag){
		check(mid-1,minstep);
	}else{
		return false;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int l=0,r=n,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,1)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid;
		}
		//cout<<l<<" "<<r<<endl;
	}
	
	cout<<ans;
	return 0;
} 

/*
4 3
2 1 0 3
*/
