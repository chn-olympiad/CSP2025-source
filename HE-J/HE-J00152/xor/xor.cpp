#include<bits/stdc++.h>
//#include<string>
//#include<algorithm>
//#include<cstdio>
//#include<>
using namespace std;
vector<pair<int,int> >v;
int a[15005];
int s[15005];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	if(n>15000){
		for(int i=1;i<=n;i++){
			int t;
			
			cin>>t;
			if(t==k)ans++;
		}
		cout<<ans;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		//	cout<<k;
			if((s[j]^s[i-1])==k){
		//	cout<<(s[j]^s[i-1])<<' ';
				v.push_back(make_pair(i,j));
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	
	int last=-1;
	for(int i=0;i<v.size();i++){
	//	cout<<v[i].first<<' '<<v[i].second<<endl;
		if(v[i].first>last){
			ans++;
			last=v[i].second;
			
		}
	}
	cout<<ans;
	return 0;
	/*rp++rp++rp++
	I can't write the right answer to T3
	but I can get 300 scores by write baoli
	It takes me 1 hour writing baoli for all questions
	but it takes 3 hours thinking the answer to T3
	and I don't know answer
	if I can't get the first price of csp-j
	I have to go out of oi
	rp++rp++rp++rp++
	I want to go to The No.1 middle school
	unless it,I can't join in NOIP
	I never give up
	but I can't still know the answer to T3 T4
	As long as you have a brain
	you can do T1 T2 right
	but T3 T4 I only can use baoli
	They are really difficult
	rp++rp++rp++
	The csp-s in afternoon is mach more difficult than csp-j
	I only can get 100
	I even think that I can't deal T1
	I like oi very much
	I like ccf
	I like csp
	I like luogu
	I'm from Shijiazhuang Hebei 
	The test is ending
	rp++rp++rp++rp++rp++*100
	I think the toliet of Yanshan university should improve
	It is too 114514
	rp++rp++rp++
	I seem already to give up
	Hurry up in csp-s!
	rp++rp++rp++rp++
	I want to be on the show of inunderstanding actions
	rp++rp++rp++
	I am the wakest in my school
	One of my greadmate said that he can AK
	The first test gread
	J80.5 S71
	I am a student in Gread 9
	Last year I get 210
	I don't know what baoli is that time
	but now I know
	So my gread will increase
	rp++rp++rp++
	I learn cpp by myself
	Students in The No.2 middle school are not human
	I like csp
	I like ccf
	rp++rp++rp++
	Today I slept 5 hours
	one hour more than last year
	I get to Qinghuangdao by train
	from 20:33 to 6:33+1
	If you don't open long long
	you will see you grandparents and the ten years oi will become empty
	I am an oier
	I love oi
	I am a girl
	rp++rp++rp++rp++
	Don't use define int long long
	Csp-s rp++rp++
	The judge computer has 96GB memorize
	That sounds unbelievable
	My computer's is 8GB
	Last year is 64GB
	It is so big but believable
	My School's computer's is 16 or 32GB
	rp++rp++rp++
	I hate Linux
	so I am using Windows
	lenovo yyds
	To xor or not to xor
	AI is fw
	It made many wrongs
	I like sf
	Sfw yyds
	Now is 12:00
	Test end
	rp++rp++rp++
	*/
}
