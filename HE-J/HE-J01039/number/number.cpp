#include<bits/stdc++.h>
using namespace std;
string n;
int shu[1000010];
int ans=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//#Shang4Shan3Ruo6Shui4	©\O2 ©\std=c++14 ©\static -static-libgcc
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int l=n.size();
	for(int i=0;i<l;i++){
		if(char(n[i])=='0'){
			shu[ans++]=0;
		}
		else if(char(n[i])=='1'){
			shu[ans++]=1;
		}
		else if(char(n[i])=='2'){
			shu[ans++]=2;
		}
		else if(char(n[i])=='3'){
			shu[ans++]=3;
		}
		else if(char(n[i])=='4'){
			shu[ans++]=4;
		}
		else if(char(n[i])=='5'){
			shu[ans++]=5;
		}
		else if(char(n[i])=='6'){
			shu[ans++]=6;
		}
		else if(char(n[i])=='7'){
			shu[ans++]=7;
		}
		else if(char(n[i])=='8'){
			shu[ans++]=8;
		}
		else if(char(n[i])=='9'){
			shu[ans++]=9;
		}
	}
	sort(shu+1,shu+1+ans,cmp);
	for(int i=1;i<ans;i++){
		cout<<shu[i];
	}
	return 0;
} 
