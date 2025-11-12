#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n,q,sl[N],t1l[N],t2l[N],ans;
char c;
vector <char> s1[N],s2[N],t1[N],t2[N];
bool tsqk;int mb;

int s1w[N],s2w[N],t1w[N],t2w[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	scanf("%d %d",&n,&q);
	int k;
	tsqk=1;
	c=getchar();
	for(int i=1;i<=n;i++){
		s1[i].push_back(' ');
		s2[i].push_back(' ');
		t1[i].push_back(' ');
		t2[i].push_back(' ');
		if(!('a'<=c&&c<='z'))c=getchar();
		k=0;mb=0;
		while('a'<=c&&c<='z'){
			if(!(c=='a'||(c=='b'&&mb++==0))) tsqk=0;
			s1[i].push_back(c);
			k++;
			c=getchar();
		}
		if(mb==0) tsqk=0;
		sl[i]=k;
		c=getchar();
		k=0;mb=0;
		while('a'<=c&&c<='z'){
			if(!(c=='a'||(c=='b'&&mb++==0))) tsqk=0;
			s2[i].push_back(c);
			k++;
			c=getchar();
		}
		if(mb==0) tsqk=0;
	}
	for(int i=1;i<=q;i++){
		c=getchar();
		k=0;mb=0;
		while('a'<=c&&c<='z'){
			if(!(c=='a'||(c=='b'&&mb++==0))) tsqk=0;
			t1[i].push_back(c);
			k++;
			c=getchar();
		}
		if(mb==0) tsqk=0;
		c=getchar();
		t1l[i]=k;
		k=0;mb=0;
		while('a'<=c&&c<='z'){
			if(!(c=='a'||(c=='b'&&mb++==0))) tsqk=0;
			t2[i].push_back(c);
			k++;
			c=getchar();
		}
		if(mb==0) tsqk=0;
		t2l[i]=k;
	}
	if(tsqk==1){
		for(int i=1;i<=n;i++){
			for(int l=1;l<=sl[i];l++){
				if(s1[i][l]=='b'){
					s1w[i]=l;
					break;
				}
			}
			for(int l=1;l<=sl[i];l++){
				if(s2[i][l]=='b'){
					s2w[i]=l;
					break;
				}
			}
		}
		for(int i=1;i<=q;i++){
			for(int l=1;l<=t1l[i];l++){
				if(t1[i][l]=='b'){
					t1w[i]=l;
					break;
				}
			}
			for(int l=1;l<=t2l[i];l++){
				if(t2[i][l]=='b'){
					t2w[i]=l;
					break;
				}
			}
		}
		for(int i=1;i<=q;i++){
			ans=0;
			for(int j=1;j<=n;j++){
				//printf("__%d %d %d %d\n",t1w[i],t2w[i],s1w[i],s2w[i]);
				if(t1w[i]-t2w[i]==s1w[j]-s2w[j]){
					if(t1w[i]-s1w[j]>=0&&t2w[i]-s2w[j]>=0){
						if((t1l[i]-t1w[i])-(sl[j]-s1w[j])>=0&&(t2l[i]-t2w[i])-(sl[j]-s2w[j])>=0) ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=sl[i];j++){
			printf("%c",s1[i][j]);
		}
		printf("\n");
	}*/
	bool f;
	for(int i=1;i<=q;i++){
		if(t1l[i]!=t2l[i]){
			printf("0\n");
			continue;
		}
		ans=0;
		for(int j=1;j<=n;j++){
			//cout<<'?';
			for(int l=1;l<=t1l[i]-sl[j]+1;l++){
				//cout<<'!';
				if(s1[j][1]==t1[i][l]&&s2[j][1]==t2[i][l]){
					//printf("_%d %d %d\n",i,j,l);
					f=1;
					for(int r=2;r<=sl[j];r++){
						if(!(s1[j][r]==t1[i][l+r-1]&&s2[j][r]==t2[i][l+r-1])){
							f=0;
							break;
						}
					}
					if(f){
						//cout<<'1';
						for(int r=1;r<l;r++){
							if(t1[i][r]!=t2[i][r]){
								f=0;
								break;
							}
						}
						//cout<<'2';
						if(!f) break;
						for(int r=l+sl[j];r<=t1l[i];r++){
							if(t1[i][r]!=t2[i][r]){
								f=0;
								break;
							}
						}
						//cout<<'3';
						if(f){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
