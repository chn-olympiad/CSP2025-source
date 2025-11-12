#include<bits/stdc++.h>
using namespace std;

int n,q;
string sa1[200005],sa2[200005];
string ta1[200005],ta2[200005];
int lens[200005];

int sol(int k){
	int ans=0;
	string tt1=ta1[k];
	
	int lent=tt1.size();

	for(int i=0;i<lent;i++){//替换区间左端点位置 
		for(int j=1;j<=n;j++){//第j个s 
			
			string ty1=tt1;
			string s1=sa1[j],s2=sa2[j];
//			cout<<"zuo:"<<i<<" s1:"<<s1<<endl;
			for(int l=0;l<lens[j];l++){//替换 
				
				if(ty1[i+l]==s1[l]){
//					cout<<"ty_"<<i+l<<':'<<ty1[i+l]<<" to "<<s2[l]<<endl;
					ty1[i+l]=s2[l];
					
				}else{
					break;
				}
			}
//			cout<<ty1<<endl;
			if(ty1==ta2[k]){
				ans++;
			}
		}
		
	}
	return ans;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa1[i]>>sa2[i];
		lens[i]=sa1[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>ta1[i]>>ta2[i];
	}
	
	for(int i=1;i<=q;i++){
//		cout<<endl<<endl;
		cout<<sol(i)<<endl;
	}
} 
