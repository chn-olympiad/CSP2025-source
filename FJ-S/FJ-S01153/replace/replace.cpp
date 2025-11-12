#include<bits/stdc++.h>
using namespace std;
int n,q,zs;
string s1,s2;
map<int,string>a[200005];
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	while(q--){
		zs=0; 
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
//		for(int i=0;i<s1.size();i++){
//			string sss2="";
//			for(int k=i;k<s1.size();k++){
//				string sss="",sss1="";
//				for(int j=i;j<k;j++)
//					sss1+=s1[j];
//				for(int j=k;j<s1.size();j++)
//					sss+=s1[j];
//				cout<<sss1<<"　"<<sss<<endl;
//				for(int j=1;j<=n;j++){
//					cout<<endl<<endl<<sss2+sss1+a[j][2]<<endl<<endl;
//					if(sss==a[j][1]&&sss2+sss1+a[j][2]==s2)
//						zs++;
//				}
//				cout<<zs<<endl;
//			}
//			sss2+=s1[i];
//			cout<<endl<<endl<<sss2<<endl<<endl;
//		}
//		cout<<zs;
////		for(int i=1;i<=n;i++){
////			if(a[i][1].size()>s1.size()){
////				cout<<"长度不符"<<endl;
////				continue;
////			}
////			int z=0,s=0,f=0,ff=0;
////			string ys="";
////			for(int j=0;j<s1.size();j++){
////				if(s1[j]==a[i][1][j+1]){
////					if(ff==0){
////						s=j;
////						ff=1;
////					}
////					z++;
////				}
////				if(s1[j]!=a[i][1][j]&&ff){
////					f=j-1;
////					break;
////				}
////			}
////			cout<<"开始"<<s<<"　"<<"结束"<<f<<"　"; 
////			for(int j=s;j<=f;j++)
////				ys+=s2[j];
////			cout<<"内容"<<ys<<"　"; 
////			if(a[i][2]!=ys){
////				cout<<"替换后不同"<<endl;
////				continue;
////			}
////			if(z==a[i][1].size())
////				zs++;
////			else
////				cout<<"尺寸不同"<<endl;
////		}
////		cout<<zs;
		s1+=' ';
		s2+=' ';
		int f=0,s=0,t=0,z=0;
		string ss="",ss1="";
		for(int i=0;i<s1.size();i++){
			if(!f){
				if(s1[i]==s2[i])
					continue;
				f=1;
				s=i;
			}
			if(f){
				if(s1[i]!=s2[i])
					continue;
				t=i-1;
				break;
			}
		}
//		cout<<s<<" "<<t<<" ";
		for(int i=s;i<=t;i++){
			ss+=s1[i];
			ss1+=s2[i];
		}
//		cout<<ss<<endl;
		for(int i=1;i<=n;i++){
			if(ss==a[i][1]&&ss1==a[i][2])
				z++;
		}
		cout<<z<<endl;
	}
	return 0;
}
