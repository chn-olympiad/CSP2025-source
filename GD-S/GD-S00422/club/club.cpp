#include <iostream>
#include <fstream>
using namespace std;
int t;
int cac[300003];
int currmax = 0;
void Bf(int index,int club,int p1co,int p2co,int p3co,int cur,int n)
{
	//cout << "currindex:" << index << " club:" << club << " p1:" << p1co << " p2:" << p2co<<" p3:" << p3co << " cur" << cur << endl;
	if(cur >currmax)
			currmax = cur;
	if(index >= n<<1)
	{
		
		return;
	}
	int bas = index*3;
	if(club == 1)
	{
		if(p1co +1 > n)
		return;
		p1co++;
		cur += cac[bas]; 
	}
	else if(club == 2)
	{
		if(p2co +1 > n)
		return;
		p2co++;
		cur += cac[bas+1]; 
	}
	else
	{
		if(p3co +1 > n)
		return;
		p3co++;
		cur += cac[bas+2]; 
	}
	Bf(index+1,1,p1co,p2co,p3co,cur,n);
	Bf(index+1,2,p1co,p2co,p3co,cur,n);
	Bf(index+1,3,p1co,p2co,p3co,cur,n);
}
void B(int index,int p1co,int p2co,int p3co,int cur,int n)
{
	if(index >= 2*n)
	{
		if(cur >currmax)
			currmax = cur;
		return;
	}
	int bas = index*3;
	if(cac[bas] > cac[bas+1])//1>2
	{
		if(cac[bas+1] > cac[bas+2])//2>3
		{
			//1>2>3
			if(p1co+1 <=n)
			{
				p1co++;
				cur += cac[bas];
				//cout << "1Add1:" << p1co << "curr:" << cur << endl;
			}
			else if(p2co+1 <=n)
			{
				p2co++;
				cur += cac[bas+1];
				//cout << "1Add2:" << p2co << "curr:" << cur << endl;
			}
			else if(p3co+1 <=n)
			{
				p3co++;
				cur += cac[bas+2];
				//cout << "1Add3:" << p3co << "curr:" << cur << endl;
			}
		}
		else//2<3,1>2
		{
			if(cac[bas] > cac[bas+2])//1>3
			{
				//1>3>2
				if(p1co+1 <=n)
				{
					p1co++;
					cur += cac[bas];
				//cout << "2Add1:" << p1co << "curr:" << cur << endl;
				}
				else if(p3co+1 <=n)
				{
					p3co++;
					cur += cac[bas+2];
				//cout << "2Add3:" << p3co << "curr:" << cur << endl;
				}
				else if(p2co+1 <=n)
				{
					p2co++;
					cur += cac[bas+1];
				//cout << "2Add2:" << p2co << "curr:" << cur << endl;
				}
			}
			else//1<3
			{
				//3>1>2
				if(p3co+1 <=n)
				{
					p3co++;
					cur += cac[bas+2];
				//cout << "3Add3:" << p3co << "curr:" << cur << endl;
				}
				
				
				else if(p1co+1 <=n)
				{
					p1co++;
					cur += cac[bas];
				//cout << "3Add1:" << p1co << "curr:" << cur << endl;
				}
				else if(p2co+1 <=n)
				{
					p2co++;
					cur += cac[bas+1];
				//cout << "3Add2:" << p2co << "curr:" << cur << endl;
				}
			}
		}
	}
	else//1<2
	{
		if(cac[bas+1] < cac[bas+2])//2<3
		{
			//3>2>1
			if(p3co+1 <=n)
			{
				p3co++;
				cur += cac[bas+2];
				//cout << "4Add3:" << p3co << "curr:" << cur << endl;
			}
			
			else if(p2co+1 <=n)
			{
				p2co++;
				cur += cac[bas+1];
				//cout << "4Add2:" << p2co << "curr:" << cur << endl;
			}
			else if(p1co+1 <=n)
			{
				p1co++;
				cur += cac[bas];
				//cout << "4Add1:" << p1co << "curr:" << cur << endl;
			}
		}
		else//2>3
		{
			if(cac[bas] > cac[bas+2])//1>3
			{
				//2>1>3
				if(p2co+1 <=n)
				{
					p2co++;
					cur += cac[bas+1];
				//cout << "5Add2:" << p2co << "curr:" << cur << endl;
				}
				
				else if(p1co+1 <=n)
				{
					p1co++;
					cur += cac[bas];
				//cout << "5Add1:" << p1co << "curr:" << cur << endl;
				}
				else if(p3co+1 <=n)
				{
					p3co++;
					cur += cac[bas+2];
				//cout << "5Add3:" << p3co << "curr:" << cur << endl;
				}
			}
			else//3>1
			{
				//2>3>1
				if(p2co+1 <=n)
				{
					p2co++;
					cur += cac[bas+1];
				//cout << "6Add2:" << p2co << "curr:" << cur << endl;
				}
				
				else if(p3co+1 <=n)
				{
					p3co++;
					cur += cac[bas+2];
				//cout << "6Add3:" << p3co << "curr:" << cur << endl;
				}
				else if(p1co+1 <=n)
				{
					p1co++;
					cur += cac[bas];
				//cout << "6Add1:" << p1co << "curr:" << cur << endl;
				}
			}
		}
	}
	B(index+1,p1co,p2co,p3co,cur,n);
}

int main()
{
	ifstream fi("club.in");
	ofstream fo("club.out");
	fi >> t;
	//cin >> t;
	
	for(int i =0 ; i< t;i++)
	{
		currmax = 0;
		int n = 0;
		//cin >> n;
		fi >> n;
		int maxpep = n/2;
		for(int mi = 0; mi < n; mi++)
		{
			//cin >> cac[mi*3] >> cac[mi*3+1] >> cac[mi*3+2];
			fi >> cac[mi*3] >> cac[mi*3+1] >> cac[mi*3+2];
		}
		Bf(0,1,0,0,0,0,maxpep);
		Bf(0,2,0,0,0,0,maxpep);
		Bf(0,3,0,0,0,0,maxpep);
		//cout << currmax;
		fo << currmax;
		if(i +1 < t)
			fo << endl;
	}
	
	return 0;
}
