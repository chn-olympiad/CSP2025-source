#include<bits/stdc++.h>
using namespace std;
long long n,q,an,o,o2,oo,len,len2;
string a[200010],b[200010],ca,cb,wa[2010],waa[2010],wb[2010],wbb[2010];
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	if(n<=100&&q<=100){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=q;i++){
			cin>>ca>>cb;
			len=ca.size();
			wa[0]=ca[0];
			wb[0]=cb[0];
			waa[len-1]=ca[len-1];
			wbb[len-1]=cb[len-1];
			for(int j=1;j<len;j++)wa[j]=wa[j-1]+ca[j],wb[j]=wb[j-1]+cb[j];
			for(int j=len-2;j>0;j--)waa[j]=ca[j]+waa[j+1],wbb[j]=cb[j]+wbb[j+1];
			an=0;
			for(int j=1;j<=n;j++){
				o=o2=0;
			//	cout<<j<<' '<<a[j]<<' '<<b[j]<<':'<<endl;
				len2=a[j].size();
			    while(ca.find(a[j],o)!=-1&&cb.find(b[j],o2)!=-1){
			    	o=ca.find(a[j],o);
			    	oo=cb.find(b[j],o2);
			    //	cout<<o<<' '<<oo<<' '<<wa[o-1]<<' '<<wb[o-1]<<' '<<waa[o+len2]<<' '<<wbb[o+len2]<<endl;
			    	if(o==oo&&wa[o-1]==wb[o-1]&&waa[o+len2]==wbb[o+len2])an++,o2=oo+1;
			    	if(o>oo)o2=oo+1;
			    	o++;
				}
			//	cout<<endl<<endl;
			}
			cout<<an<<endl;
		}
	}
	return 0;
}

