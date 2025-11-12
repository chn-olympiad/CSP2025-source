#include<bits/stdc++.h>
using namespace std;
int n,q,len1,len2,cnt;
string sonstr,s_1[200005],s_2[200005],t_1,t_2;
string sss(string st,int l,int r){
	if(r-l+1<0) return "";
	return st.substr(l,r-l+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s_1[i]>>s_2[i];
	}
	for(int iii=0;iii<q;iii++){
		cin>>t_1>>t_2;cnt=0;
		t_1=" "+t_1+" ",t_2=" "+t_2+" ";
		len1=t_1.size(),len2=t_2.size();
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		for(int l=0;l<len1;l++){
			for(int len=0;len+l<len1;len++){
				int r=l+len-1;
				string t1fr=sss(t_1,0,l-1),t1md=sss(t_1,l,r),t1ba=sss(t_1,r+1,len1);
				string t2fr=sss(t_2,0,l-1),t2md=sss(t_2,l,r),t2ba=sss(t_2,r+1,len2);
				if(t1fr==t2fr&&t1ba==t2ba){
					for(int i=0;i<n;i++){
						if(s_1[i]==t1md&&s_2[i]==t2md){
							cnt++;
						}
					}
				}
			}
		}cout<<cnt<<endl;cnt=0;
	}
	return 0;
}