#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
bool cmp(long long a,long long b){
	return a>b;
}
string s;
long long arr[maxn];
long long count1=0;
int main(){
	//#Shang4Shan3Ruo6Shui4
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[count1++]=s[i]-'0';
		}
	}
	sort(arr,arr+count1,cmp);
	for(int i=0;i<count1;i++){
		cout<<arr[i];
	}
	
	
	
	
	return 0;
} 
