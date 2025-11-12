#include<bits/stdc++.h>
using namespace std;
long long n,q;
int s1[200005][2];
int s2[200005][2];
int t1[200005][2];
int t2[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string q1,q2;
		cin>>q1>>q2;
		int sl=q1.size();
		//cout<<sl<<endl;
		for(int j=0;j<sl;j++){
			
			if(q1[j]=='b')break;
			//cout<<q1[j]<<" ";
			s1[i][0]=j+1;
		//	cout<<s1[i][0]<<endl;
		}
		s1[i][1]=sl-1-s1[i][0];
		for(int j=0;j<sl;j++){
			if(q2[j]=='b')break;
			s2[i][0]++;
		}
		s2[i][1]=sl-1-s2[i][0];
	}
	for(int i=1;i<=q;i++){
		string q1,q2;
		cin>>q1>>q2;
		int sl1=q1.size();
		int sl2=q2.size();
		if(sl1!=sl2){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<sl1;j++){
			if(q1[j]=='b')break;
			else t1[i][0]++;
		}
		t1[i][1]=sl1-1-t1[i][0];
		for(int j=0;j<sl2;j++){
			if(q2[j]=='b')break;
			else t2[i][0]++;
		}
		t2[i][1]=sl2-1-t2[i][0];
		int x=t1[i][0]-t2[i][0];
		//cout<<t1[i][0]<<" "<<t2[i][0]<<" ";
		long long sum=0;
		for(int j=1;j<=n;j++){
			if(s1[j][0]-s2[j][0]==x && (s1[j][0]<=t1[j][0] && s1[j][1]<=t1[j][1]) && (s2[j][0]<=t2[j][0] && s2[j][1]<=t2[j][1])) sum++;
		}
		cout<<sum<<endl;
	}
	
	//for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	//for(int i=1;i<=q;i++) cout<<t[i]<<" ";
	return 0;
}
