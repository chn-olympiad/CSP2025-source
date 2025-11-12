#include<bits/stdc++.h>
using namespace std;
struct sss {
	string fr,me1,me2,ed;
}aaa[1000005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string str1,str2,str="",str3="",str4="",str5="";
		cin>>str1>>str2;
		int jjj=0;
		for(int j=jjj; j<str1.size(); j++) {
			if(str1[j]==str2[j]) {
				str=str+str1[j];
				jjj=j+1;
			} else {
				//str3=str3+str1[j];
				jjj=j;
				break;
			}
		}
		for(int j=jjj; j<str1.size(); j++) {
			if(str1[j]!=str2[j]) {
				str3=str3+str1[j];
				str4=str4+str2[j];
				jjj=j+1;
			} else {
				//str5=str5+str1[j];
				jjj=j;
				break;
			}
		}
		for(int j=jjj; j<str1.size(); j++) {
			str5=str5+str1[j];
		}
		aaa[i]={sss{str,str3,str4,str5}};
		//cout<<str<<" "<<str3<<" "<<str4<<" "<<str5<<endl;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string str1,str2,str="",str3="",str4="",str5="";
		cin>>str1>>str2;
		int j=0;
		for(; j<str1.size(); j++) {
			if(str1[j]==str2[j]) {
				str=str+str1[j];
			} else {
				//str3=str3+str1[j];
				break;
			}
		}
		for(; j<str1.size(); j++) {
			if(str1[j]!=str2[j]) {
				str3=str3+str1[j];
				str4=str4+str2[j];
			} else {
				//str5=str5+str1[j];
				break;
			}
		}
		for(; j<str1.size(); j++) {
			str5=str5+str1[j];
		}
		for(int k=1;k<=n;k++){
			int fffff=0;
			if(str3==aaa[k].me1 && str4==aaa[k].me2){
				fffff=1;
				for(int kk=1;kk<=aaa[k].fr.size();kk++){
					if(str[str.size()-kk]!=aaa[k].fr[aaa[k].fr.size()-kk]){
						fffff=-1;
						break;
					}
				}
				if(fffff){
					break;
				}
				for(int kk=1;kk<=aaa[k].ed.size();kk++){
					if(str5[kk-1]!=aaa[k].ed[kk-1]){
						fffff=-1;
						break;
					}
				}
			}
			if(fffff==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
