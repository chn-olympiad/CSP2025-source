#include<bits/stdc++.h>
using namespace std;
int n,q,k,sp=1;
string s1,s2,t1,t2;
struct node{
	string s1;
	string s2;
	int pos1;
	int pos2;
	int pos;
	int sum1;
	int sum2;
	bool operator < (const node &a) const{
		if(pos!=a.pos) return pos<a.pos;
		else return max(sum1,sum2)<max(a.sum1,a.sum2);
	}
};
node sm[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		sm[k].s1=s1,sm[k].s2=s2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!='a'&&s1[i]!='b') sp=0;
			if(s1[i]=='b') sm[k].pos1=i;
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]!='a'&&s2[i]!='b') sp=0;
			if(s2[i]=='b') sm[k].pos2=i;
		}
		sm[k].pos=sm[k].pos1-sm[k].pos2;
		sm[k].sum1=sm[k].pos1;
		sm[k].sum2=s1.size()-sm[k].pos2;
	}
	if(sp==1){
		int ans=0;
		sort(sm,sm+k);
		for(int i=0;i<q;i++){
			int pos1=0,pos2=0,pos=0,cnt1=-1,cnt2=-1,sum1,sum2;
			cin>>t1>>t2;
			for(int i=0;i<t1.size();i++){
				if(t1[i]=='b') pos1=i;
			}
			for(int i=0;i<t2.size();i++){
				if(t2[i]=='b') pos2=i;
			}
			pos=pos1-pos2;
			sum1=pos1;
			sum2=t1.size()-pos2;
			int l=0,r=k-1;
			while(l<=r){
				int mid=(l+r)/2;
				if(sm[mid].pos>pos) r=mid-1,cnt2=mid;
				else l=mid+1,cnt1=mid;
			}
			if(cnt1==-1){
				cout<<0<<endl;
			}else{
				for(int cs=cnt1;cs<cnt2;cs++){
					if(sm[cs].sum1<=sum1&&sm[cs].sum2<=sum2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else{
		for(int i=0;i<q;i++) cout<<"0\n";
	}
	return 0;
}
