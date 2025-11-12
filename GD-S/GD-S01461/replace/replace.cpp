#include<bits/stdc++.h>
using namespace std;
map<string,string> t;
int n,q,ans;
string s_1,s_2,t_1,t_2,c_1,c_2;
void sdzc(int i,int j){
	t_1="b";
	t_2="b";
	for(int a=i;a<j;a++) t_1 = t_1+'a';
	for(int b=j;b>i;b--) t_2 = 'a'+t_2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>t_1>>t_2;
		t[t_1]=t_2;
	}
	while(q--){
		ans = 0;
		i = 0;
		j = 0;
		cin>>s_1>>s_2;
		while(s_1[i]!='b') i++;
		while(s_2[j]!='b') j++;
		if(i<=j){
			sdzc(i,j);
			c_1 = t_1;
			c_2 = t_2;
			while(i>=0){
				if(t[c_1]==c_2) ans++;
				c_1 = 'a'+c_1;
				c_2 = 'a'+c_2;
				i--;
			}
			c_1 = t_1;
			c_2 = t_2;
			while(j<s_1.size()){
				if(t[c_1]==c_2) ans++;
				c_1 = c_1+'a';
				c_2 = c_2+'a';
				j++;
			}
		}
		else{
			sdzc(j,i);
			c_1 = t_2;
			c_2 = t_1;
			while(j>=0){
				if(t[c_1]==c_2) ans++;
				c_1 = 'a'+c_1;
				c_2 = 'a'+c_2;
				j--;
			}
			c_1 = t_2;
			c_2 = t_1;
			while(i<s_1.size()){
				if(t[c_1]==c_2) ans++;
				c_1 = c_1+'a';
				c_2 = c_2+'a';
				i++;
			}			
		}
		cout<<ans<<endl;
	}
	return 0;
}
