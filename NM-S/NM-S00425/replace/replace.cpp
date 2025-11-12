#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n],b[n];
	int ans=0;
	for(int i=0;i<n;i++){cin>>a[i]>>b[i];}
	string ques[q],ansq[q];
	for(int i=0;i<q;i++)cin>>ques[i]>>ansq[i];
	for(int i=0;i<q;i++){
		string aas=ques[i];
		//int k=0;
		for(int j=0;j<aas.length()*aas.length();j++){
			
			for(int k=j+1;k<aas.length();k++){
			//k++;
			
				int l=aas.length()-j-k+1;
				string x,y,z;
				for(char c:aas){
					if(j!=0)x+=c,j--;
					else if(j==0&&k!=0)y+=c,k--;
					else if(j==0&&k==0&&l!=0)z+=c,l--;
				}
				for(int p=0;p<q;p++){
					if(a[p]==y)y=b[p];
					}
				if(x+y+z==ansq[i])ans++;
				//if(k==aas.length())k=j;
				}
			
		}
			cout<<ans<<endl;	
			}
	
	
	return 0;
}
