#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int y=0;
	while(s[y]!='\0'){
		y++;
	}
	int i=0;
	int arr[y];
	int o=0;
	for(;i<y;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[i]=int(s[i])-48;
			o++;
		}
		
	}
	
	for(int n=0;n<y;n++){
		for(int m=y-1;m>=n+1;m--){
			if(arr[m]>arr[m-1]){
				swap(arr[m],arr[m-1]);
			}
		}
	}
	for(int z=0;z<o;z++){
		cout<<arr[z];
	}
	return 0;
}
