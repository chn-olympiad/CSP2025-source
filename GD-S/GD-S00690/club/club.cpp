#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
struct student_{
	int m[4],pos1,pos2;
	student_ (): pos1(-1),pos2(-1){
	}
	bool operator <(const student_& other)const {
		if(m[pos1]==other.m[pos1])
			return m[pos2]>other.m[pos2];
		return m[pos1]>other.m[pos1];
	}
}st[N];
bool Acmp(student_ a,student_ b);
void chose_(int i),baoli(int pos);
int n,max_to,n_to[4],ans,s;//
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club2.in","r",stdin);
	int TTT;
	cin>>TTT;
	while(TTT--){
		int k=false;
		ans=0,s=0;
		cin>>n;
		max_to=n/2;
		for(int i=1;i<=n;i++){
			cin>>st[i].m[1]>>st[i].m[2]>>st[i].m[3];
			if(st[i].m[2]||st[i].m[3])
				k=true;
			//chose_(i);
		}
		if(!k){
			sort(st+1,st+n+1,Acmp);
			for(int i=1;i<=max_to;i++)
				s+=st[i].m[1];
		}	
		else
			baoli(1);
	/*	sort(st+1,st+n+1);
		for(int i=1;i<=n;i++){
			;
		}*/
		
		
		
		cout<<s<<endl;
	}
	
	
	return 0;
}
void chose_(int i){
	if(st[i].m[1]>st[i].m[2]){
		if(st[i].m[1]>st[i].m[3]){
			st[i].pos1=1;
			if(st[i].m[2]>st[i].m[3])
				st[i].pos2=2;
			else
				st[i].pos2=3;
		}	
		else
			st[i].pos1=3,st[i].pos2=1;
	}
	else{//m2>m1
		if(st[i].m[2]>st[i].m[3]){
			st[i].pos1=2;
			if(st[i].m[1]>st[i].m[3])
				st[i].pos2=1;
			else
				st[i].pos2=3;
		}
		else 
			st[i].pos1=3,st[i].pos2=2;
	}
	return ;
}
void baoli(int pos){
	if(pos>n){
		s=max(ans,s);
		return ;
//cout<<"test:"<<s<<endl;
	}
	if(n_to[1]<max_to){
		n_to[1]++;
		ans+=st[pos].m[1];
//cout<<"pos="<<pos<<" i="<<1<<" +ans="<<ans<<endl;
		baoli(pos+1);
		n_to[1]--;
		ans-=st[pos].m[1];
//cout<<"returnpos="<<pos<<" i="<<1<<" +ans="<<ans<<endl;
	}
	if(n_to[2]<max_to){
		n_to[2]++;
		ans+=st[pos].m[2];
///cout<<"pos="<<pos<<" i="<<2<<" +ans="<<ans<<endl;
		baoli(pos+1);
		n_to[2]--;
		ans-=st[pos].m[2];
//cout<<"returnpos="<<pos<<" i="<<2<<" +ans="<<ans<<endl;
	}
	if(n_to[3]<max_to){
		n_to[3]++;
		ans+=st[pos].m[3];
//cout<<"pos="<<pos<<" i="<<3<<" +ans="<<ans<<endl;
		baoli(pos+1);
		n_to[3]--;
		ans-=st[pos].m[3];
///cout<<"returnpos="<<pos<<" i="<<3<<" +ans="<<ans<<endl;
	}
	return ;
}
bool Acmp(student_ a,student_ b){
	return a.m[1]>b.m[1];
}
