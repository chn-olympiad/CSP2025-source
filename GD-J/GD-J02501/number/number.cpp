#include<bits/stdc++.h>
std::string s;
int arr[1000001],flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	int len=s.size();
	for (int i=0;i<len;i++){
		if (s[i]>='0' && s[i]<='9') {
			flag++;
			arr[flag]=s[i]-'0';
		}
	}
	for (int i=1;i<=flag-1;i++){
		for (int j=i+1;j<=flag;j++){
			if (arr[j]>arr[i]){
				int k=arr[i];
				arr[i]=arr[j];
				arr[j]=k;
			}
		}
	}
	for (int i=1;i<=flag;i++) printf("%d",arr[i]);
	return 0;
}
