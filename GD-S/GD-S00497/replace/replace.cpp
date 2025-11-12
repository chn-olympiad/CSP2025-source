#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,bd[100005][2005];
string arr[100005][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s1,s2; 
	for(int i=1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1];
//		arr[i][0]="a"+s1;
//		arr[i][1]="a"+s2;
	}
//	for(int a=1;a<=n;a++){
//		bd[a][0]=0;
//		for(int i=1,j=0;i<arr[a][0].length();i++){
//			while(j>0&&arr[a][j+1]!=arr[a][i]) j=bd[a][j];
//			bd[a][i]=j;
//			if(arr[a][j+1]==arr[a][i]) j++;
//		}
//	}
	string str1,str2;
	for(int z=1;z<=q;z++){
		cin>>str1>>str2;
		int cnt=0;
		for(int a=1;a<=n;a++){
			string scnt;
			for(int i=0;i+arr[a][0].length()-1<str1.length();i++){
				if(i>0) scnt+=str1[i-1];
				bool flag=1;
				for(int j=0;j<arr[a][0].length();j++){
					if(str1[i+j]!=arr[a][0][j]){
						flag=0;
						break;
					}
				}
				if(flag){
//					cout<<scnt<<' ';
					string stmp;
					for(int j=i+arr[a][0].length();j<str1.length();j++) stmp+=str1[j];
//					cout<<stmp<<'\n';
					if(scnt+arr[a][1]+stmp==str2) cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
