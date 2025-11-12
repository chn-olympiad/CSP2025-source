#include<bits/stdc++.h>
using namespace std;

string a;
long long ans[10000005];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	int len=a.size();
	int j=1;
	//cout<<len<<endl; 
	for(int i=0;i<len;i++){
		if(a[i]>='0' and a[i]<='9'){
			ans[j]=a[i]-'0';
			j++;
		}
	}
	//for(int i=1;i<=j;i++)	cout<<ans[i]<<" ";
	sort(ans+1,ans+j,cmp);
	for(int i=1;i<j;i++){
		cout<<ans[i];
	}
	return 0;
} 
