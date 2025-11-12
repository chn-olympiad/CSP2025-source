#include<iostream>
#include<cstring>
using namespace std;
int numsum[20],t_size;
bool flag=0;
string text;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>text;
	t_size=text.size();
	for(int i=0;i<t_size;i++)
		if(text[i]>='0'&&text[i]<='9')numsum[text[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(i!=0&&numsum[i]!=0)flag=1;
		if(i==0&&!flag)cout<<'0';
		else{
			for(int j=1;j<=numsum[i];j++){
				cout<<(char)('0'+i);
			}
		}
	}
	cout<<endl;
	return 0;
}
