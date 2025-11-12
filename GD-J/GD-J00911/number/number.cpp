#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	char tidai;
	int ans=0;
	cin>>s;
	int a=s.size();
	int z[a];
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			z[ans]=s[i];
			ans++;
		}
	} 
	if(ans>1){
		for(int i=0;i<=ans;i++){
			for(int j=0;j<=ans;j++){
				if(z[i]<=z[i+1]){
					tidai=z[i];
					z[i]=z[i+1];
					z[i+1]=tidai;
				}
			}
		}
		for(int i=0;i<ans;i++){
			char q=z[i];
			cout<<q;
		}
	}else{
		char p=z[0];
		cout<<p;
	}	
} 
