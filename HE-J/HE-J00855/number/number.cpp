#include<bits/stdc++.h>
using namespace std;
const int big=1e6;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	long long len=s.size();
	long long num=0,ans=0;
	
	for(int i=0;i<len;i++){
		if(s[i]>'9'||s[i]<'0'){
			s[i]='\0';
		}
	}
	len=s.size();
	long long num_max,arr[len];
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			arr[i-num]=s[i]-'0';
			ans++;
		}else{
			num++;
		}
	}
	for(int i=0;i<ans;i++){
		for(int j=i;j<ans-1;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				break;
			}
		}
		
	}

	for(int i=0;i<ans;i++){
		cout<<arr[i];
	}
	return 0;
}
