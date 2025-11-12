#include<bits/stdc++.h>
using namespace std;
int m,n;
struct manba_out{
	string a,b;
};
//经试验
//c.substr(a,b)截取c字符串从下标为a开始长度为b个字符的字符串
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	manba_out c[m];
	for(int i=0;i<m;i++){
		cin>>c[i].a>>c[i].b;
	}
    string question,wanna;
    for(int j=0;j<n;j++){
    	cin>>question;
		cin>>wanna;
		int ans=0;
		for(int i=0;i<m;i++){
			string x;
			int key=0;
			int weizhi=question.find(c[i].a);
			if(weizhi>-1){ 
				string b=question;
				for(int j=0;j<c[i].a.size();j++){
					b[weizhi+j]=c[i].b[j];
					 
				}//更改后的字符串 
				int key=0;
				for(int j=0;j<b.size();j++){
					if(b[j]!=wanna[j]){
						key=1;
						break;
					}
				}//查重 
				if(key==0) ans++; 
			}
		}
		cout<<ans<<endl;
	}
	//依旧凑字节                                                                                                              
	return 0;
}
