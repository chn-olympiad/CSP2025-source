#include<bits/stdc++.h> 
using namespace std;
string s;
char a[1000005];
int b[100005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	} 
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i];
			k++;
		}
		
	}
	
	for(int i=0;i<k;i++){
		b[i]=a[i]-'0';
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(b[j+1]>b[j]){
				swap(b[j+1],b[j]);
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	
return 0;
}
