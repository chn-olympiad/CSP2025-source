#include<bits/stdc++.h>
using namespace std;
int ans=0,a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'){
			ans++;
			a[i]=1;
		}else if(s[i]=='2'){
			ans++;
			a[i]=2; 
		}else if(s[i]=='3'){
			ans++;
			a[i]=3; 
		}else if(s[i]=='4'){
			ans++;
			a[i]=4; 
		}else if(s[i]=='5'){
			ans++;
			a[i]=5; 
		}else if(s[i]=='6'){
			ans++;
			a[i]=6; 
		}else if(s[i]=='7'){
			ans++;
			a[i]=7; 
		}else if(s[i]=='8'){
			ans++;
			a[i]=8; 
		}else if(s[i]=='9'){
			ans++;
			a[i]=9; 
		}else if(s[i]=='0'){
			ans++;
			a[i]=0; 
		}
	}
	for(int i=0;i<=ans;i++){
		for(int j=0;j<=ans;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
    }
	for(int i=0;i<=ans;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
    fclose(stdout);
	return 0;
}
