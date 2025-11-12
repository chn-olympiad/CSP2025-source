using namespace std;
int main(){
	freopen("number.in.","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	char m[1000001];
	int j=0;
	for(int i=0;i<=n.length()-1;i++){
		if (isdigit(n[i])){
			m[j]=n[i];
			j++;
		}
	}
	sort(m,m+j);
	for(int i=j;i>=0;i--){
		cout<<m[i];
	}
	return 0;
}