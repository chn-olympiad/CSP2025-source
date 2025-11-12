#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1&&(s[0]>='0'&&s[0]<='9')){
		cout<<s;
		return 0;
	}
	int shu=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			shu+=1;
		}
		else{
			continue;
		}
	} 
	int sum=-1,ans=0;
	for(int i=0;i<shu;i++){
		sum+=1;
		ans=sum+1;
		for(int j=0;j<shu;j++){
			if(a[sum]<a[ans]){
				swap(a[sum],a[ans]);
				ans+=1;
			}
			else{
				ans+=1;
			}
		}
	}
	for(int i=0;i<shu;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
