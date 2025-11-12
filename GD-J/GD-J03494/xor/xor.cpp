#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,s[500005];
/*
void dfs(int s,int an){
	if (s>n){
		return ;
	}
	cout<<s<<" "<<an<<"\n";	
	int b=a[s];
	if (b==k){
		dfs(s+1,an+1);
		ans=max(an,ans);
		return ;
	}
	for (int i=s+1;i<=n;i++){
		b=b^a[i];
		if (a[i+1]==k && b!=k){
			dfs(i+1,an);
			break;
		}
		if (b==k){
			dfs(i+1,an+1);
			break;
		}
	}
	ans=max(an,ans);
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i==1){
			s[i]=a[i];
			continue;
		}
		s[i]=s[i-1]^a[i];
	}
	/*
	for (int i=1;i<=n;i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n";
	*/
	for (int i=1;i<=n;i++){
		int an=0;
		int f=0;
		if (a[i]==k){
			an++;
			i++;
		}
		int st=i,j=i+1;
		while (j<=n){
			if (a[st]==k || a[j]==k){
				//cout<<st<<" "<<j<<" "<<an<<"\n";				
				f=1;
				st=j+1;
				an++;
			}
			else if (s[j]==k && i==1 && f==0){
				f=1;
				an++;
			}
			else if (s[j]^s[st-1]==k && i!=1){
				/*
				cout<<st<<" "<<j<<" "<<an;
				//cout<<s[j]^s[st-1];
				cout<<"\n";
				*/
				f=1;
				an++;
				st=j+1;
			}
			j++;
		}
		ans=max(an,ans);
	}
	/*
	for (int i=1;i<=n;i++){
		dfs(i,0);
	}
	*/
	cout<<ans;
	return 0;
} 
