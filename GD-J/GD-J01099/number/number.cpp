#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
using namespace std;

int cnt[11];
string s,ans;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number3.in","r",stdin);
//	freopen("number3.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=" "+s;
	bool a0=true;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
			if(s[i]!='0')a0=false;
		}
	}
	if(a0){
		cout<<0;
		akioi;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			ans.push_back((char)(i+'0'));
			cnt[i]--;
		}
	}
	cout<<ans;
	akioi;
}
