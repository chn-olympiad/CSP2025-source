#include<bits/stdc++.h>
using namespace std;
int n,q,ans,aa[200005];
string s1[200005],s2[200005],a,b;
bool op=1,opp=1;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int ls1=s1[i].size(),sum_a1=0,sum_a2=0;
		bool ob1=0,ob2=0;
		for(int j=0;j<ls1;j++){
			if(s1[i][j]!='b'&&ob1==0)
			sum_a1++;
			else{
				if(ob1==1&&s2[i][j]=='b')
				op=0;
			ob1=1;
		}
			if(s2[i][j]!='b'&&ob2==0)
			sum_a2++;
			else{
				if(ob2==1&&s2[i][j]=='b')
				op=0;
			ob2=1;
		}
		if((s1[i][j]!='a'&&s1[i][j]!='b')||(s2[i][j]!='a'&&s2[i][j]!='b')){
			op=0;
		}
		}
		aa[i]=sum_a1-sum_a2;
	}
	while(q--){
		cin>>a>>b;
		int la=a.size(),lb=b.size();
		if(la!=lb){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		if(op==1){
			int sum_a1=0,sum_a2=0;
		bool ob1=0,ob2=0;
			for(int i=0;i<la;i++){
				if(a[i]!='b'&&ob1==0){
					sum_a1++;
			}else{
				if(ob1==1&&a[i]=='b')
				opp=0;
				ob1=1;
			}
			if(b[i]!='b'&&ob2==0)
			sum_a2++;
			else{
				if(ob2==1&&b[i]=='b')
				opp=0;
			ob2=1;
		}
		if((b[i]!='a'&&b[i]!='b')||(a[i]!='a'&&a[i]!='b')){
			opp=0;
		}
		}
		int k=sum_a1-sum_a2;
		//cout<<k<<endl;
		if(opp==1){
			for(int i=1;i<=n;i++){
				if(k==aa[i])
				ans++;
		}
		cout<<ans<<"\n";
		continue;
		}
		//
	}
	
		for(int i=0;i<la;i++){
			for(int j=1;j<=n;j++){
				bool op=1;
				int ls1j=s1[j].size();
				for(int k=i,p=0;p<ls1j;k++,p++){
					if(s1[j][p]!=a[k]){
						op=0;
				    }
				}
				if(op==1){
					string s3;
					for(int k=0;k<i;k++){
						s3+=a[k];
				    }
				    int ls2j=s2[j].size();
				    for(int k=0;k<ls2j;k++){
						s3+=s2[j][k];
					}
					for(int k=i+ls2j;k<la;k++){
						s3+=a[k];
				    }
				    if(s3==b){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
    }
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
