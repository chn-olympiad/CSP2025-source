#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	char a[100005];
	cin>>a;
	int s[100005];
	int cnt=0;
	for(int i=0;i<100005;i++)s[i]=-1;
		for(int i=0;i<100005;i++){
		if(a[i]<='9'&&a[i]>='0'){
		s[cnt]=a[i]-'0';
		cnt++;
		}
		else{
			if(a[i]<'z'&&a[i]>'A')continue;
			else{
				break;
			}
		}
	}
	sort(s,s+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
	fclose(stdin);
    fclose(stdout); 
    
	
}
