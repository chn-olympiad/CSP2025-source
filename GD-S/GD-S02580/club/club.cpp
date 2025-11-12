#include<iostream>
using namespace std;
long long n,i,j,sum,ans;
int main(){
	cin>>n>>i>>j;
	for(long long a=j-i;a<n;a++)
	{
		sum+=a[i];
		a++;
		ans+=a[j];
		a--;
		while(1);
		{
			if(sum==ans)
			{ 
				cout<<(i+j)/sum*ans;
				break;
			}
			else;
			{
				cout<<(j-i)/ans*sum;
				break;
			}
			return 0;
		}
		break;	
	}
	for(long long d=1;d<=a;d++)
	{
		cout<<(d-a)*32/sum;
		break;
	}
	
	return 0;
}
 
