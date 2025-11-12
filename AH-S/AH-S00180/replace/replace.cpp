#include<bits/stdc++.h>
using namespace std;
	/*string str="aabbcc";
	* string s=str.substr(1,4);
	* s=="abbc";
	*/
#define N 200005
string s[N][3];
int n,q;
int cnt=0;
string u,v;
int fun(int fst,int lst,int num){//使用第num组si进行替换
	int len=s[num][1].size(),ulen=u.size();
	//cout<<len<<" "<<ulen<<" "<<fst<<" "<<lst<<" "<<lst-len+1<<" ";
	if(len>ulen) return 0;
	//cout<<"i = "<<max(0,lst-len+1)<<" . limit: i + "<<len<<" < "<<ulen<<" and i < "<<fst<<endl; 
	for(int i=max(0,lst-len+1);(i+len)<=ulen && i<=fst;i++){
		string str=u.substr(i,len),ans=v.substr(i,len);
		if(s[num][1]==str && s[num][2]==ans) return 1;
	//	cout<<i<<" is not right\n";
	}
	return 0;
}
void answer(){
	if(n>10000 || q>10000){cout<<0<<endl;return ;}
	if(v.size()!=u.size()){cout<<0<<endl;return ;}
	cnt=0;//reset cnt
	int fst=-1,lst=-1,ulen=u.size();
	for(int i=0;i<ulen;i++){//寻找首次不同与最后不同，进行优化
		if(u[i]!=v[i]){
			lst=i;//update lst
			if(fst==-1) fst=i;//fst
		}
	}
	for(int i=0;i<n;i++){
		cnt+=fun(fst,lst,i);//使用第i组si进行替换
	}
	cout<<cnt<<endl;
	return ;
}
int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=0;i<q;i++){
		cin>>u>>v;
		answer();
	}
	return 0;
}
